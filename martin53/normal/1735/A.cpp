#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int n;

        Solution()
        {
            scanf("%i",&n);
        }

        void solve()
        {
            printf("%i\n",(n-6)/3);
        }
};

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        Solution current;

        current.solve();
    }

    return 0;
}