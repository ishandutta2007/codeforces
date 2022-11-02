# include <iostream>
# include <cstdio>
# include <cstring>

int abs(int x){
    return x<0?-x:x;
}

using namespace std;
const int D = 75;

int a[2][151][151];
int L = 0, R = 0, k=0, t=0;

int n,m;
int main()
{
    cin >> n >> m;
    a[1][0+D][0+D] = n;
    while(true)
    {
        for(int i=D-L; i<=D+L; i++)
            for(int j=D-L; j<=D+L; j++)
                if(a[k^1][i][j]>=4)
                {
                    t = a[k^1][i][j]/4;
                    a[k][i][j] += a[k^1][i][j]%4;
                    a[k][i+1][j] += t;
                    a[k][i-1][j] += t;
                    a[k][i][j+1] += t;
                    a[k][i][j-1] += t;
                    if((i+1)>R)R=i+1;
                }
                else a[k][i][j] += a[k^1][i][j];
        if(!t) break;
        memset(a[k^1],0,sizeof(a[k^1]));
        k^=1; t=0; L=R-D;
    }
    k^=1;
    
    int x,y;
    while (m--)
    {
        cin >> x >> y;
        if(abs(x)>75 || abs(y)>75)
            cout << 0;
        else
            cout << a[k][x+D][y+D];
        cout << endl;
    }

/*
    k^=1;
    for(int i=D-L; i<=D+L; i++)
    {
        for(int j=D-L; j<=D+L; j++)
            cout << a[k][i][j]<<' ';
        cout << endl;
    }
*/
    return 0;
}