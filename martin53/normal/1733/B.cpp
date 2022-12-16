#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        int n,x,y;

    public:
        Solution()
        {
            scanf("%i%i%i",&n,&x,&y);
        }
        void solve()
        {
            if(x>y)swap(x,y);

            if(x>0||y==0)
            {
                printf("-1\n");
                return;
            }

            if((n-1)%y)
            {
                printf("-1\n");
                return;
            }

            for(int i=1;i<=n;i+=y+(i==1))
            {
                for(int j=1;j<=y;j++)
                    printf("%i ",i);
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