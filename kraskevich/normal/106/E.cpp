#include <iostream>
#include <cstdio>
using namespace std;

#define sqr(a) (a) * (a)

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    double x[n], y[n], z[n];
    
    for(int i = 0; i < n; ++i)
            cin >> x[i] >> y[i] >> z[i];
    
    double xx = 0, yy = 0, zz = 0, inc = 1;
    
    for(int i = 0; i < 20000; ++i)
    {
            double d = -1;
            int num;
            
            for(int j = 0; j < n; ++j)
            {
                    double cur = sqr(x[j] - xx) + sqr(y[j] - yy) + sqr(z[j] - zz);
                    if(cur >= d)
                           d = cur, num = j;
            }
            
            xx += (x[num] - xx) * inc;
            yy += (y[num] - yy) * inc;
            zz += (z[num] - zz) * inc;
            inc *= 0.999;
    }
    
    cout.setf(ios::fixed);
    cout.precision(10);
    
    cout << xx << " " << yy << " " << zz << endl;
    
    cin >> n;
    
    return 0;
}