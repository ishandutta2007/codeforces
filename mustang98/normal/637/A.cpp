#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

map<int, int> m;

int main()
{
    int a, n, maxlike=0, ans;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        if (m.count(a)==0) m[a]=0;
        m[a]++;
        if (m[a] > maxlike)
        {
            maxlike = m[a];
            ans = a;
        }
    }
    cout<<ans;
    return 0;
}