#include <iostream>
using namespace std;
int cur,a[305];
void send(int l,int r)
{
	cout << "? " << l << ' ' << r << endl;
	cin >> cur;
	cout << "? " << l << ' ' << r << endl;
	cin >> cur;
}
int main()
{
	cout.flush();
	int n,t;
	cin >> n >> t;
	cur=t;
	string s="! "+string(n,'0');
	if (n%2)
	{
		for (int i=1;i<n;i++)
		{
			int tmp=cur;
			while (tmp==cur)
			send(i,i+1);
			a[i]=(cur-(n-tmp)+2)/2;
			tmp=cur;
			while (tmp==cur)
			send(i,i+1);
		}
		for (int i=1;i<n;i+=2)
		t-=a[i];
		s[n+1]+=t;
		for (int i=n;i>1;i--)
		s[i]+=a[i-1]-(s[i+1]-'0');
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			int tmp=cur;
			while (tmp==cur)
			send(i,i);
			if (cur>n-tmp)
			s[i+1]++;
			tmp=cur;
			while (tmp==cur)
			send(i,i);
		}
	}
	cout << s;
}