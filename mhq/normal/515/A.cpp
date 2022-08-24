#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int a,b,s;

int main()
{   cin>>a>>b>>s;
    if ( abs(a) + abs(b) > s) {
        cout<<"No";
    }
    else {
        if ( (abs(a) + abs(b)) % 2 != s % 2 ) {
            cout<<"No";
        }
        else {
            cout<<"Yes";
        }
    }
    return 0;
}