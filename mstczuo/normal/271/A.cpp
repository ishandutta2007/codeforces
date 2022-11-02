# include <iostream>
# include <cstdio>
using namespace std;

int c[9000];
int n,x;

int main()
{
    for(int i=1;i<=9;i++)
        for(int j=0;j<=9;j++)if(i!=j)
            for(int s=0;s<=9;s++)if(i!=s&&j!=s)    
                for(int t=0;t<=9;t++)if(i!=t&&j!=t&&s!=t)
                    c[n++]=i*1000+j*100+s*10+t;
    cin >> x;
    for(int i=0;i<n;i++)
        if(c[i]>x){
            cout<<c[i]<<endl;
            return 0;
        }
}