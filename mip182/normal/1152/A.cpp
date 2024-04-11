#include <iostream>
#include <cmath>
using namespace std;
int main(){
long long n,m,chests=0,antichests=0,antikeys=0,keys=0;
cin>> n>>m;
for (long long i=1; i<=n;i++)
{
    int x;
    cin >> x;
    if (x%2==0)
    chests=chests+1;
    else
    antichests=antichests +1;
}
for (long long j=1; j<=m;j++)
{   int y;
    cin>> y;
    if (y%2==0)
    keys=keys+1;
    else
    antikeys=antikeys+1;
}
long long answer = min(chests,antikeys) + min(antichests,keys);
cout << answer;
}