#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int INF = 10000000;

void relaxMin(int &x, int y) {
    x = min(x, y - 1);
}

void relaxMax(int &x, int y) {
    x = max(x, y + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, x, y;
    scanf("%d", &n);
    
    int minX, minY, minSum, minDiff;
    int maxX, maxY, maxSum, maxDiff;
    
    minX = minY = minSum = minDiff = INF;
    maxX = maxY = maxSum = maxDiff = -INF;
    
    REP(i, n) {
        scanf("%d%d", &x, &y);
        
        relaxMin(minX, x);
        relaxMin(minY, y);
        relaxMin(minSum, x + y);
        relaxMin(minDiff, x - y);
        
        relaxMax(maxX, x);
        relaxMax(maxY, y);
        relaxMax(maxSum, x + y);
        relaxMax(maxDiff, x - y);
        
    }

    //cerr << minX << ' ' << minY << ' ' << minSum << ' ' << minDiff << '\n';
    //cerr << maxX << ' ' << maxY << ' ' << maxSum << ' ' << maxDiff << ' ';
    
    int x1 = minSum - minY;
    int x2 = maxDiff + minY;

    //cerr << x1 << ' ' << x2 << '\n';
    
    int y1 = maxX - maxDiff;
    int y2 = maxSum - maxX;

    //cerr << y1 << ' ' << y2 << '\n';
    
    int x3 = maxSum - maxY;
    int x4 = minDiff + maxY;

    //cerr << x3 << ' ' << x4 << '\n';
    
    int y3 = minX - minDiff;
    int y4 = minSum - minX;

    //cerr << y3 << ' ' << y4 << '\n';
    
    int ans = abs(x2 - x1) + abs(y2 - y1) + abs(x4 - x3) + abs(y4 - y3) +
              abs(maxX - x2) + abs(maxX - x3) + abs(minX - x1) + abs(minX - x4);
    
    cout << ans;
}