# include <iostream>
using namespace std;

long long sol(long long a,long long b,long long c)
{
    return a/3 + b/3 + c/3;
}

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    long long ans = 0;
    
    ans = max(ans, sol(r,g,b));
    
    if(r>0 && g>0 && b>0)
        ans = max(ans, sol(r-1,g-1,b-1)+1);
    
    if(r>1 && g>1 && b>1)
        ans = max(ans, sol(r-2,g-2,b-2)+2);
    
    cout << ans << endl;
    return 0;
}