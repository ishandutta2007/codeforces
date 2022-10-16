#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxSiz = 100005;

struct Point {
    int x, y;
    Point(){}
    Point(int dx, int dy) : x(dx), y(dy) {}

    Point operator-(const Point other) const {
        return Point(x-other.x, y-other.y);
    }

    LL cross_prod(const Point other) const {
        return (LL)x * other.y - (LL)y * other.x;
    }

    bool operator<(const Point other) const {
        return (x < other.x);
    }
};

int N, M;
Point A[MaxSiz], B[MaxSiz];

void input(){
    scanf("%d%d%*d%*d", &N, &M);
    int x, y;
    for(int i = 0; i < N; i++){
        scanf("%d%d", &x, &y);
        A[i] = Point{x,y};
    }
    for(int i = 0; i < M; i++){
        scanf("%d%d", &x, &y);
        B[i] = Point{x,y};
    }
}

vector<Point> envelope;
int maxRight;

void make_envelope(){
    Point maxX{0,0}, maxY{0,0};

    for(int i = 0; i < M; i++){
        if(B[i].x > maxX.x) maxX = B[i];
        if(B[i].y > maxY.y) maxY = B[i];
    }

    maxRight = maxX.x;
    envelope.emplace_back(0, maxY.y);

    sort(B, B+M);

    envelope.push_back(B[0]);
    int S = 2;

    for(int i = 1; i < M; i++){
        while(S >= 2){
            Point prevVec = envelope[S-1] - envelope[S-2];
            Point nextVec = B[i] - envelope[S-1];
            if(prevVec.cross_prod(nextVec) > 0){
                envelope.pop_back();
                S--;
            } else {
                break;
            }
        }

        envelope.push_back(B[i]);
        S++;
    }
}

int main(){
    input();
    make_envelope();

    for(int i = 0; i < N; i++){
        if(A[i].x >= maxRight){
            printf("Max\n");
            return 0;
        }

        int pos = distance(envelope.begin(),
                prev(upper_bound(envelope.begin(), envelope.end(), A[i])));

        Point envVec = envelope[pos+1] - envelope[pos],
              pntVec = A[i] - envelope[pos];

        if(envVec.cross_prod(pntVec) >= 0){
            printf("Max\n");
            return 0;
        }
    }
    printf("Min\n");
    return 0;
}