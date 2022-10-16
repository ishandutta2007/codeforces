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

ll r,x,y,x1,y2;

void init(void)
{
    cin>>r>>x>>y>>x1>>y2;
}

void process(void)
{
    ll a=ceil(sqrt((x-x1)*(x-x1)+(y-y2)*(y-y2))/(r*2));
    cout<<a;
}

int main(void)
{
    init();
    process();
    return 0;
}