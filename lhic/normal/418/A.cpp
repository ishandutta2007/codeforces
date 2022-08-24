#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;

int n,k;

void makeLoop(int x)
{
    for (int i=0;i<n;++i)
    {
        a.push_back(i);
        b.push_back((i+x)%n);
    }
}

int main()
{
    cin>>n>>k;
    if ((n-1)/2 <  k)
    {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=k;++i)
    {
        makeLoop(i);
    }
    cout<<a.size()<<"\n";
    for (int i=0;i<a.size();++i)
        cout<<a[i]+1<<" "<<b[i]+1<<"\n";
}