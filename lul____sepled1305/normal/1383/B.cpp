/**Nephren is the best girl**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,i,j;
        int maxi = -1;
        int num = 1;
        int decide = false;
        int A_win = true;
        cin>>n;
        int val[n];
        for(i=0;i<n;i++)
        {
            cin>>val[i];
            maxi = val[i];
        }
        for(j=0;j<29;j++)
            num*=2;
        while(num>0)
        {
            int counti = 0;
            for(i=0;i<n;i++)
            {
                if(val[i]>=num)
                    counti++;
            }
            if(counti%4==1)
            {
                decide = true;
                break;
            }
            else if(counti%4==3)
            {
                decide = true;
                if(n%2==1)
                    A_win = false;
                break;
            }
            else
            {
                for(i=0;i<n;i++)
                {
                    if(val[i]>=num)
                        val[i]-=num;
                }
                num/=2;
            }
        }
        if(!decide)
            cout<<"DRAW\n";
        else if(A_win)
            cout<<"WIN\n";
        else
            cout<<"LOSE\n";
    }
    return chtholly;
}

/**
    I lied. Ithea is better than Nephren.
    JK
**/