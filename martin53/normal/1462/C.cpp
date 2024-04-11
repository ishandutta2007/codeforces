#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        int n;
        scanf("%i",&n);

        vector<int> outp={};

        for(int j=9;j>=1;j--)
            if(n>=j)
            {
                outp.push_back(j);
                n=n-j;
            }

        if(n!=0)
        {
            printf("-1\n");
            continue;
        }

        for(int i=outp.size()-1;i>=0;i--)printf("%i",outp[i]);printf("\n");
    }

    return 0;
}