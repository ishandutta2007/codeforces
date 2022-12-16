#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        int n,k;

        vector< vector<int> > input;

    public:
        Solution()
        {
            scanf("%i%i",&n,&k);

            for(int i=1;i<=n;i++)
            {
                vector<int> row={};

                for(int j=1;j<=k;j++)
                {
                    int cur;

                    scanf("%i",&cur);

                    row.push_back(cur);
                }

                input.push_back(row);
            }
        }

        void solve()
        {
            vector<int> cnt(n,0);

            map< vector<int>, int> which;

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    vector<int> remain={};

                    for(int p=0;p<k;p++)
                        remain.push_back((6-input[i][p]-input[j][p])%3);

                    if(which.count(remain))
                    {
                        cnt[i]++;
                        cnt[j]++;
                        cnt[which[remain]]++;
                    }
                }

                which[input[i]]=i;
            }

            long long output=0;

            for(int i=0;i<n;i++)
                output+=1LL*cnt[i]*(cnt[i]-1)/2;

            printf("%lld\n",output);
        }
};

int main()
{
    Solution current;

    current.solve();

    return 0;
}