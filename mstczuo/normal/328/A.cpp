# include <iostream>

using namespace std;

int a,b,c,d;

int main()
{
    cin >> a >> b >> c >> d;
    
    int f = b - a;
    if ( b+f==c && c+f==d ) {
        cout << d+f << endl;
        return 0;
    }
    
    if ( b*b==a*c && c*c==b*d ) {
        if(d*d%c==0)
        {
            cout << d*d/c << endl;
            return 0;
        }
    }
    
    cout << 42 << endl;
    return 0;
    
}