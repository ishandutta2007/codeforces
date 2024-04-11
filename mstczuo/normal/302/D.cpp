# include <iostream>
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
const int N=101;
int x[N],y[N],c[N],a[N][N],i,j,k,n,d;

int main()
{
    cin >> n >> d;
    for( i=2; i<n; i++)
        cin >> c[i];
    for( i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    for( i=1; i<=n; i++)
        for( j=1; j<=n; j++)
            if(i!=j){
                a[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
                a[i][j] = a[i][j] * d - c[i];
            }
    for( k=1; k<=n; k++)
        for( i=1; i<=n; i++) if( k-i )
            for( j=1; j<=n; j++) if( k-j && i-j )
                if( a[i][k]+a[k][j]<a[i][j] ) a[i][j]=a[i][k]+a[k][j];
    cout << a[1][n] << endl;
    return 0;
}