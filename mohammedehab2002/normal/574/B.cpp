#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class war{
    public:
        int r;
        vector <int> v;
        war(){
            r=-2;
        }
        void add(int ind){
            v.push_back(ind);
        }
        int get_size(){
            return v.size();
        }
};
int main()
{
    int n,m,i,x,j,a,b,mini=100000;
    cin >> n >> m;
    war arr[n+1];
    for (i=0;i<m;i++)
    {
        cin >> a >> b;
        arr[a].r++;
        arr[b].r++;
        arr[a].add(b);
        arr[b].add(a);
    }
    for (i=1;i<=n;i++)
    {
    	if (arr[i].r<0)
    	continue;
        for (x=0;x<arr[i].get_size()-1;x++)
        {
            for (j=x+1;j<arr[i].get_size();j++)
            {
                if (find(arr[arr[i].v[x]].v.begin(),arr[arr[i].v[x]].v.end(),arr[i].v[j])!=arr[arr[i].v[x]].v.end())
                {
                    if (arr[i].r+arr[arr[i].v[x]].r+arr[arr[i].v[j]].r<mini)
                    mini=arr[i].r+arr[arr[i].v[x]].r+arr[arr[i].v[j]].r;
                }
            }
        }
    }
    if (mini==100000)
    cout << -1;
    else
    cout << mini;
}