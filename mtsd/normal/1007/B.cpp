#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

#define MAX_N 100010

vector<int> pr[MAX_N],id[MAX_N];
vector<int> sz(MAX_N);
bool is_prime[MAX_N];

void allfac(int n)
{
    fill(is_prime,is_prime+n+1,true);
    sz[1] = 1;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            pr[i].push_back(i);
            id[i].push_back(1);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
                int cnt = 0;
                int nw = j;
                while(nw % i == 0){
                    nw /= i;
                    cnt++;
                }
                pr[j].push_back(i);
                id[j].push_back(cnt);
            }
        }
    }
    for(int i=2;i<=n;i++){
        sz[i] = 1;
        for(int j=0;j<id[i].size();j++){
            sz[i] *= id[i][j]+1;
        }
    }
}

int gcd(int v,int b){
	if(v>b) return gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return gcd(v,b%v);
}
int calc(int x){
    return (x*(x-1))/2+x;
}

int main(){
    int t;
    cin >> t;
    allfac(100005);
    ll ma = 0;
    rep(zz,t){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        int ans = 0;
        int xy = gcd(x,y);
        int yz = gcd(y,z);
        int zx = gcd(z,x);
        int xyz = gcd(x,gcd(y,z));
        int a,b,c,d,e,f,g;
        int xs,ys,zs;
        xs= sz[x];
        ys= sz[y];
        zs= sz[z];
        a = sz[x]-sz[xy]-sz[zx]+sz[xyz];
        b = sz[y]-sz[xy]-sz[yz]+sz[xyz];
        c = sz[z]-sz[yz]-sz[zx]+sz[xyz];
        d = sz[xy]-sz[xyz];
        e = sz[yz]-sz[xyz];
        f = sz[zx]-sz[xyz];
        g = sz[xyz];
        ans += a*b*(zs);
        ans += a*d*(zs);
        ans += a*e*(c+f+g);
        ans += a*calc(e);
        ans += a*g*(c+f);
        ans += a*calc(g);
        ans += d*b*zs;
        ans += zs*(calc(d));
        ans += d*e*(c+f+g);
        ans += d*(calc(e));
        ans += d*g*c;
        ans += d*g*f;
        ans += d*(calc(g));
        ans += f*b*(c+e+g);
        ans += b*calc(f);
        ans += f*d*c;
        ans += d*calc(f);
        ans += f*e*c;
        ans += f*calc(e);
        ans += e*calc(f);
        ans += f*e*g;
        ans += f*g*c;
        ans += g*calc(f);
        ans += f*calc(g);
        ans += g*b*(c+e);
        ans += b*calc(g);
        ans += g*e*c;
        ans += g*calc(e);
        ans += e*calc(g);
        ans += c*calc(g);
        ans += (g*(g-1)*(g-2))/6;
        ans += g*(g-1)+g;
        printf("%d\n",ans);
    }
    return 0;
}