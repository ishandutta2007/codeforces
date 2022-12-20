#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n;
long long arr[nmax],help[nmax];
long long output=1;

mt19937 rng(42);

int main()
{
    int T;
    T=clock();
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);


    while(1.0*(clock()-T)/CLOCKS_PER_SEC<3.5)
    {
        int pos=rng()%n+1;

        for(int j=1;j<=n;j++)
            help[j]=__gcd(arr[j],arr[pos]);

        vector<long long> divs,seen;
        for(long long d=1;d*d<=arr[pos];d++)
            if(arr[pos]%d==0)
            {
                divs.push_back(d);
                seen.push_back(0);
                if(d!=arr[pos]/d)
                {
                    divs.push_back(arr[pos]/d);
                    seen.push_back(0);
                }
            }
        sort(divs.begin(),divs.end());

        for(int i=1;i<=n;i++)
        {
            int add=lower_bound(divs.begin(),divs.end(),help[i])-divs.begin();
            seen[add]++;
        }

        //for(int i=0;i<divs.size();i++)cout<<divs[i]<<" "<<seen[i]<<"\t";cout<<endl;

        for(int i=0;i<divs.size();i++)
        {
            int current=0;
            for(int j=i;j<divs.size();j++)
                if(divs[j]%divs[i]==0)
                    current=current+seen[j];

            //cout<<i<<" -> "<<current<<endl;

            if(current>=(n+1)/2)
                output=max(output,divs[i]);
        }
    }

    printf("%lld\n",output);
    return 0;
}