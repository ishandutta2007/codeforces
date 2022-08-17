#include <iostream>

using namespace std;

int main()
{
    int n,d,h;
    cin>>n>>d>>h;
    if (d>2*h) {cout<<-1; return 0;}
    int cur=2;
    int S;
    if (d==1 && n>2) {cout<<-1; return 0;}
    S=1;
    if (h==d) S=h;
    for (int i=0;i<h;i++)
    {
        cout<<cur-1<<' '<<cur<<endl;
        cur++;
    }
    for (int i=0;i<d-h;i++)
    {
        if (i==0) cout<<1<<' '<<cur<<endl;
        else cout<<cur-1<<' '<<cur<<endl;
        cur++;
    }
    while (cur<=n)
    {
        cout<<S<<' '<<cur<<endl;
        cur++;
    }
    return 0;
}