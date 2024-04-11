#include <bits/stdc++.h>
using namespace std;
long long v[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long i,j,s=0,n,k,l;
    cin>>k>>n>>l;
    for(i=1;i<=n*k;++i)
        cin>>v[i];
    sort(v+1,v+n*k+1);
    for(i=1;i<=n*k && v[i]<=v[1]+l;++i);
    --i;
    if(i<k)
    {
        cout<<0;
        return 0;
    }
    int pz=i;
    j=1;
	for(i=1;i<=k;++i)
	{
		s+=v[j++];
		for(int y=1;y<n;++y) {
			if(pz-j>=k-i)
				j++;
			else
				break;
		}
	}
    cout<<s;
    return 0;
}