#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct POINT{
    POINT(){x = y = 0;}
    POINT(__int64 x_, __int64 y_){x = x_; y = y_;}
    __int64 x,y;
} POINT;
POINT P[401010],PV,A,B,T,E;
stack<POINT> S; int N;

inline __int64 ABS(__int64 a){return (a<0)?(-a):(a);}
inline __int64 MAX(__int64 a, __int64 b){return (a>b)?a:b;}
inline __int64 CCW(POINT A, POINT B, POINT C){return A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y);}
bool CMP(const POINT& a, const POINT& b){return CCW(PV,a,b) > 0;}

int main()
{
    int i,c; __int64 x,y,p;

    scanf ("%d",&N);
    for (i=0;i<N;i++){
        scanf ("%I64d %I64d",&x,&y);
        P[i*4+0] = POINT(x+1,y); P[i*4+1] = POINT(x,y+1);
        P[i*4+2] = POINT(x-1,y); P[i*4+3] = POINT(x,y-1);
    } N *= 4;

    for (i=1;i<N;i++){
        if (P[0].y > P[i].y || (P[0].y == P[i].y && P[0].x > P[i].x)){T = P[0]; P[0] = P[i]; P[i] = T;}
    }

    PV = P[0]; c = 1;
    for (i=1;i<N;i++){
        if (PV.x == P[i].x && PV.y == P[i].y){
            T = P[c]; P[c] = P[i]; P[i] = T; c++;
        }
    }
    sort(P+c,P+N,CMP);

    S.push(P[c-1]); S.push(P[c]);
    for (i=c+1;i<N;i++){
        do{ B = S.top(); S.pop(); A = S.top(); } while (CCW(A,B,P[i]) <= 0 && S.size() >= 2);
        S.push(B); S.push(P[i]);
    }

    E = T = S.top(); S.pop(); p = 0;
    while (!S.empty()){
        p += MAX(ABS(T.x-S.top().x),ABS(T.y-S.top().y)); T = S.top(); S.pop();
    }p += MAX(ABS(T.x-E.x),ABS(T.y-E.y));

    printf ("%I64d",p);

    return 0;
}