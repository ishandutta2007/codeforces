#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

using namespace std;

double dist(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt((double)((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

struct dot{
ll x, y,num;
double d;
bool used = false;
};

bool comp(dot a, dot b)
{
    return (a.d<b.d);
}

double square(dot a1, dot a2, dot a3)
{
    return 0.5*(double)((a2.x-a1.x)*(a3.y-a1.y)-(a2.y-a1.y)*(a3.x-a1.x));
}

int main()
{
    dot m[100001];
    ll n, x, y;
    int first=0, second, third;
    cin>>n;
    cin>>m[0].x>>m[0].y;
    for (int i=1;i<n;i++)
    {
        cin>>m[i].x>>m[i].y;
        m[i].num = i;
        m[i].d = dist(m[i].x, m[i].y, m[0].x, m[0].y);
    }
    //for (int i=1;i<n;i++) cout<<m[i].d<<endl;
    sort(m,m+n,comp);
    //for (int i=0;i<n;i++) cout<<m[i].num<<endl;
    second = m[1].num;
    for (int i=2; i<n;i++)
    {
        if (square(m[0], m[1], m[i]))
        {
            third = m[i].num;
            break;
        }
    }
    cout<<first+1<<' '<<second+1<<' '<<third+1;
    return 0;
}