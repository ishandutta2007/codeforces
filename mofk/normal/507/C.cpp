#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;
const ll mod=1e9+7,INFLL=1e18;

int h; ll n;

ll solve(ll n,int h)
{
    if(h==0) return 0;
    if(n<=(1LL<<h-1)) return 1+solve((1LL<<h-1)-n+1,h-1);
    return (1LL<<h)+solve(n-(1LL<<h-1),h-1);
}

void init(void)
{
    cin>>h>>n;
}

void process(void)
{
    cout<<solve(n,h);
}

int main(void)
{
    init();
    process();
    return 0;
}