# include <iostream>
# include <cstdio>
using namespace std;

long long x,y,m;
long long ans=0;

int main()
{
    cin >> x >> y >> m;
    if (x>y) swap(x,y);
    
    if(y<=0)
    {
        if (y<m) ans = -1;
        cout << ans << endl;
        return 0;
    }
    
    if(x>=m||y>=m)
        return cout<<0,0;
    
    if(x<=0){
        ans = ((-x)/y)+1;
        x+=y*ans;
    }
    
    if(x>y) swap(x,y);
    
    while(y<m)
    {
        ans++;
        x+=y;
        swap(x,y);
    }
    
    cout << ans << endl;
    return 0;
}