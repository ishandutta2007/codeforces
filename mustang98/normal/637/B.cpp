#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


set <string> s;
string m[200001];

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>m[i];
    for (int i=n-1;i>=0;i--)
        if (s.count(m[i])==0)
        {
            cout<<m[i]<<endl;
            s.insert(m[i]);
        }
    return 0;
}