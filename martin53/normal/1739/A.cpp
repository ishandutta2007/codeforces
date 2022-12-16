#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int n,m;

        Solution()
        {
            scanf("%i%i",&n,&m);
        }

        void solve()
        {
            if(n==1||m==1)printf("1 1\n");
            else printf("2 2\n");
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