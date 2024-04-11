#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int n,k;
        vector<int> s;

        Solution()
        {
            scanf("%i%i",&n,&k);

            for(int i=1;i<=k;i++)
            {
                int cur;

                scanf("%i",&cur);

                s.push_back(cur);
            }
        }

        void solve()
        {
            vector<int> numbers={};

            if(s[0]>=0)numbers.push_back((s[0]+n-k+1-1)/(n-k+1));
            else numbers.push_back(s[0]/(n-k+1));

            for(int i=1;i<s.size();i++)
                numbers.push_back(s[i]-s[i-1]);

            for(int i=1;i<numbers.size();i++)
                if(numbers[i-1]>numbers[i])
                {
                    printf("NO\n");
                    return;
                }

            printf("YES\n");
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