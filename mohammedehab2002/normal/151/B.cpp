#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
class book{
    public:
        string name;
        int type[3];
        book(){
            type[0]=type[1]=type[2]=0;
        }
};
int numtype(string s)
{
    int i,n;
    if (count(s.begin(),s.end(),s[0])==s.size()-2)
    return 0;
    for (i=0;i<s.size();i++)
    {
        if (s[i]>=n)
        return 2;
        if (s[i]!='-')
        n=s[i];
    }
    return 1;
}
int main()
{
    vector <int> m[3];
    int n,i,x,ans[]={0,0,0};
    cin >> n;
    book arr[n];
    for (x=0;x<n;x++)
    {
        int s;
        cin >> s >> arr[x].name;
        for (i=0;i<s;i++)
        {
            string num;
            cin >> num;
            arr[x].type[numtype(num)]++;
        }
    }
    for (x=0;x<n;x++)
    {
        for (i=0;i<3;i++)
        {
            if (arr[x].type[i]>ans[i])
            ans[i]=arr[x].type[i];
        }
    }
    for (x=0;x<n;x++)
    {
        for (i=0;i<3;i++)
        {
            if (arr[x].type[i]==ans[i])
            m[i].push_back(x);
        }
    }
    cout << "If you want to call a taxi, you should call: ";
    for (i=0;i<m[0].size();i++)
    {
        cout << arr[m[0][i]].name;
        if (i!=m[0].size()-1)
        cout << ", ";
    }
    cout << '.' << endl << "If you want to order a pizza, you should call: ";
    for (i=0;i<m[1].size();i++)
    {
        cout << arr[m[1][i]].name;
        if (i!=m[1].size()-1)
        cout << ", ";
    }
    cout << '.' << endl << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for (i=0;i<m[2].size();i++)
    {
        cout << arr[m[2][i]].name;
        if (i!=m[2].size()-1)
        cout << ", ";
    }
    cout << '.';
}