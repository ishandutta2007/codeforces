#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
int N,ans;
bool ch[MN];
struct point{
    int x,y,z,idx;
}P[MN];

bool cmp(point &A, point &B)
{
    if(A.x==B.x){
        if(A.y==B.y) return A.z<B.z;
        return A.y<B.y;
    }
    return A.x<B.x;
}

int dist(int i, int j)
{
    return abs(P[i].x-P[j].x)+abs(P[i].y-P[j].y)+abs(P[i].z-P[j].z);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> P[i].x >> P[i].y >> P[i].z;
        P[i].idx = i+1;
    }
    //sort(P,P+N,cmp);
    for(int i=0; i<N; i++){
        if(ch[i]) continue;
        int M = 1e9, cnt = -1;
        for(int j=i+1; j<N; j++){
            if(ch[j]) continue;
            if(dist(i,j)<M){
                M = dist(i,j);
                //cout << M << '\n';
                cnt = j;
            }
        }
        cout << i+1 << ' ' << cnt+1 << '\n';
        ch[i] = 1;
        ch[cnt] = 1;
        //cout << P[i].idx << ' ' << P[i+1].idx << '\n';
    }
}