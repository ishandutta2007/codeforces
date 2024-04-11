#include <iostream>
const int N=10000000;
using namespace std;
int poz[200005],srt[500005];
int main()
{
	int t,i,j,cnt=0,a,b,d,r,m,pr=0,pz=-1,n,q,st=250000,dr=250001;
	char c;
	cin>>q;
	while(q--)
	{
        cin>>c;
        if(c=='L')
        {
            cin>>a;
            srt[st--]=a;
            poz[a]=st+1;
        }
        else
        if(c=='R')
        {
            cin>>a;
            srt[dr++]=a;
            poz[a]=dr-1;
        }
        else
        {
            cin>>a;
            b=poz[a];
            cout<<min(dr-b,b-st)-1<<'\n';
        }
	}
}