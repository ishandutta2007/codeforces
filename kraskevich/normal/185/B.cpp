#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    
    int s, a, b, c;
    
    cin >> s >> a >> b >> c;
    
    if(a + b + c == 0)
        cout << "0 0 0" << endl;
    else
        cout <<  s * 1.0 * a / (a + b + c) << " " <<  s * 1.0 * b / (a + b + c) << " " <<
                 s * 1.0 * c / (a + b + c) << endl;
    
    return 0;
}