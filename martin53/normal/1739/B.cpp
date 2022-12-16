#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int n;
        vector<int> input;

        Solution()
        {
            scanf("%i",&n);

            for(int i=1;i<=n;i++)
            {
                int current;

                scanf("%i",&current);

                input.push_back(current);
            }
        }

        void solve()
        {
            long long prefix_sum=0;

            for(auto current:input)
            {
                if(current&&prefix_sum>=current)
                {
                    printf("-1\n");
                    return;
                }

                prefix_sum+=current;
            }

            prefix_sum=0;

            for(auto current:input)
            {
                prefix_sum+=current;

                printf("%i ",prefix_sum);
            }

            printf("\n");
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