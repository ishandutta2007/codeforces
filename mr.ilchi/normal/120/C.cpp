//In the name of Allah
//
//
#include <fstream>
#include <set>
using namespace std;
int hon[1000];
int n,k;
int res;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=0;i<n;i++)
		cin>>hon[i];
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<3;j++) if (hon[i]>=k)
			hon[i]-=k;
		res+=hon[i];
	}
	cout<<res<<endl;
	return 0;
}