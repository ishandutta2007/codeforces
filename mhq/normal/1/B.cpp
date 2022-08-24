#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
using namespace std;
int n;
bool type (string a) {
    int i;
    for ( i = a.size() - 1; i>=0; i--) {
        if ( a[i] == 'C') {
            break;
        }
    }
    if ( i == 0) {
        return false;
    }
    if ( 0<=a[i-1] - '0' && a[i-1] - '0' <=9) {
        return true;
    }
    return false;
}
void convert1( string a ) {
    int i = 0;
    while ( (a[i] - '0') > 9 || (a[i] - '0') < 1 ) {
        i++;
    }
    cout<<"R";
    for ( int j = i; j < a.size(); j++) {
            cout<<a[j];
    }
    cout<<"C";
    int t = 0;
    for ( int j = 0; j <= i - 1; j++) {
    t = t*26 + (a[j] - 'A') + 1;
    }
    cout<<t<<endl;
}
void convert2 (string a) {
    int i = 1;
    int to;
    for ( int i = 1; i <=a.size();i++) {
        if ( a[i] == 'C') {
            to = i - 1;
            break;
        }
    }
    char b[ a.size() - ( to + 2) ];
    for (int j = to + 2; j <= a.size() - 1; j++) {
        b[j - to - 2] =  a[j];
    }
    int t = atoi(b);
    string c;
    while ( t > 0) {
        if ( t % 26 == 0 ) {
            c +='Z';
            t = ( t - 26)/26;
        }
        else {
            c += ( t % 26 ) + 'A' - 1;
            t = (t - (t % 26)) / 26;
        }
    }
    for ( int i = 0; i < c.size();i++) {
        cout<<c[ c.size() - 1 - i];
    }
    for (int i = 1; i <= to - 1; i++) {
        cout<<a[i];
    }
    cout<<a[to]<<endl;
}
int main()
{   ios_base::sync_with_stdio(false);
    cin>>n;
    string a;
    for ( int i = 0; i < n; i++) {
    cin>>a;
    if ( type(a)) {
        void(convert2(a));
    }
    else {
        void(convert1(a));
    }
    }


    return 0;
}