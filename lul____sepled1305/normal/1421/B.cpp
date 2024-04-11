#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        char a[n][n];
        for(i=0;i<n;i++)
            scanf("%s",&a[i]);

        pii checki[4] = {{0,1},{1,0},{n-2,n-1},{n-1,n-2}};

        if(a[0][1] == '0' && a[1][0] == '0')
        {
            int black = 0;
            if(a[n-2][n-1] == '0')
                black++;
            if(a[n-1][n-2] == '0')
                black++;
            cout<<black<<endl;
            if(a[n-2][n-1] == '0')
                cout<<n-1<<' '<<n<<endl;
            if(a[n-1][n-2] == '0')
                cout<<n<<' '<<n-1<<endl;
        }
        else if(a[0][1] == '1' && a[1][0] == '1')
        {
            int black = 0;
            if(a[n-2][n-1] == '1')
                black++;
            if(a[n-1][n-2] == '1')
                black++;
            cout<<black<<endl;
            if(a[n-2][n-1] == '1')
                cout<<n-1<<' '<<n<<endl;
            if(a[n-1][n-2] == '1')
                cout<<n<<' '<<n-1<<endl;
        }
        else
        {
            if(a[n-2][n-1] == a[n-1][n-2])
            {
                cout<<1<<endl;
                if(a[0][1] != a[n-2][n-1])
                    cout<<2<<' '<<1<<endl;
                else
                    cout<<1<<' '<<2<<endl;
            }
            else
            {
                if(a[n-2][n-1] != a[0][1])
                {
                    cout<<2<<endl;
                    cout<<2<<' '<<1<<endl;
                    cout<<n<<' '<<n-1<<endl;
                }
                else
                {
                    cout<<2<<endl;
                    cout<<1<<' '<<2<<endl;
                    cout<<n<<' '<<n-1<<endl;
                }
            }
        }
    }
}