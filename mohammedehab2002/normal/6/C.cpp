#include <iostream>
#include <deque>
using namespace std;
class eat{
	public:
		int bar;
		int cur;
		eat()
		{
			bar=cur=0;
		}
};
int main()
{
	eat e1,e2;
	deque <int> bars;
	int n,i,a;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		bars.push_back(a);
	}
	while (bars.size()>0)
	{
		if (e1.cur!=0)
		e1.cur--;
		if (e2.cur!=0)
		e2.cur--;
		if (e1.cur==0)
		{
			e1.bar++;
			e1.cur=bars.front();
			bars.pop_front();
		}
		if (e2.cur==0 && bars.size()>0)
		{
			e2.bar++;
			e2.cur=bars.back();
			bars.pop_back();
		}
	}
	cout << e1.bar << " " << e2.bar;
}