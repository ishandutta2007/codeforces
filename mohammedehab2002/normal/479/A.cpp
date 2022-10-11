#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    set <int> s;
    s.insert(a+b+c);
    s.insert(a*b*c);
    s.insert(a+b*c);
    s.insert(a*b+c);
    s.insert((a+b)*c);
    s.insert(a*(b+c));
    cout << *max_element(s.begin(),s.end()); 
}