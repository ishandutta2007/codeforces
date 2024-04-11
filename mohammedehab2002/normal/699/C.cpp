#include <iostream>
using namespace std;
#define n(i) (i==1? 2:1)
int arr[105],ld,ans=0;
int main()
{
	bool b=false;
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
    	cin >> arr[i];
    	if (!arr[i])
    	{
    		ans++;
    		ld=0;
    		continue;
		}
    	if (!b)
    	ld=arr[i],b=true;
    	else
    	{
    		if (arr[i]==ld && ld!=3)
    		ans++,ld=0;
    		else if (arr[i]==3 && ld && ld!=3)
    		ld=n(ld);
    		else
    		ld=arr[i];
		}
	}
	cout << ans;
}