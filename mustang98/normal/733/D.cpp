#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int m[100006][3];
int n;

map<pair<int, int>, pair<int, int> > have;

int main()
{
    cin>>n;
    int ans1 = -10;
    int num1;
    int a, b, c;
    for(int i = 0; i < n; i++)
    {
        cin>>m[i][0]>>m[i][1]>>m[i][2];
        sort(m[i], m[i] + 3);
        a = m[i][0], b = m[i][1], c = m[i][2];
        if (m[i][0] > ans1)
        {
            num1 = i;
            ans1 = m[i][0];
        }
        if (a == b) continue;

        //      
        pair<int, int> p1 = make_pair(a,b), p2 = make_pair(a,c), p3 = make_pair(b,c);
        if (have.count(p1) == 0 || have[p1].F < c)
        {
            have[p1] = make_pair(c, i);
        }
        if (have.count(p2) == 0 || have[p2].F < b)
        {
            have[p2] = make_pair(b, i);
        }
        if (have.count(p3) == 0 || have[p3].F < a)
        {
            have[p3] = make_pair(a, i);
        }
    }
    //cout<<have.size()<<endl;
   // cout << have[make_pair(8, 10)].S<<endl;

    int ans = -10;
    int n1, n2;
    for (int i = 0; i < n; i++)
    {
        a = m[i][0], b = m[i][1], c = m[i][2];
        if (a == b) continue;
        pair<int, int> gp = have[make_pair(b,c)];
        if (gp.S == i) continue;
        int minn = min(b, min(c, a + gp.F));
        if (minn > ans)
        {
            ans = minn;
            n1 = i;
            n2 = gp.S;
        }
    }
    if (ans1 >= ans)
    {
        cout<<1<<endl;
        cout<<num1 + 1;
    }
    else
    {
        cout<<2<<endl;
        cout<<n1 + 1<<' '<<n2 + 1<<endl;
    }
    return 0;
}