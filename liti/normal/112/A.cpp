#include <iostream>
using namespace std;

int main() { 
    string a,b;
    cin >> a >> b;
    
    for( int i = 0 ; i < a.size() ; i++ ) if( a[i] >= 'a' ) a[i] -= 'a' - 'A';
    for( int i = 0 ; i < b.size() ; i++ ) if( b[i] >= 'a' ) b[i] -= 'a' - 'A';
    cout << ( a==b ? 0 : ( a < b ? -1 : 1 ) ) << endl;
}