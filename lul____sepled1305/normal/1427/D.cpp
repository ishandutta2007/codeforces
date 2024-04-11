/**Ogiso Setsuna**/
#include<bits/stdc++.h>
using namespace std;
int n,i,j;
vector<int> v;
vector<int> ans[52];

void merge(vector<int> &v, vector<int> change)
{
    vector<int> temp;
    int siz = v.size();
    int pointer = n-1;
    while(pointer >= 0)
    {
        int cur = change.back();
        change.pop_back();
        int res = pointer - cur+1;
        while(cur > 0)
        {
            temp.push_back(v[res]);
            res++;
            cur--;
            pointer--;
        }
    }
    v = temp;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        a--;
        v.push_back(a);
    }
    while(i > 1)
    {
        i--;
        int cur,prv,nxt = n;
        for(j=0;j<n;j++)
        {
            if(v[j] == i+1)
                nxt = j;
            if(v[j] == i)
                cur = j;
            if(v[j] == i-1)
                prv = j;
        }
        bool as = (nxt > cur);
        if(false)
        {
            ;
        }
        else
        {
            int temp[n];
            if(prv < cur)
            {
                if(as)
                {
                    for(j=0;j<prv;j++)
                        ans[i].push_back(1);
                    ans[i].push_back(cur - prv);
                    for(j=cur;j<n;j++)
                        ans[i].push_back(1);
                }
                else
                {
                    for(j=0;j<prv;j++)
                        ans[i].push_back(1);
                    int cu = 0;
                    for(j=prv; j<n ;j++)
                    {
                        if(v[j] == n-1)
                            break;
                        else
                            cu++;
                    }
                    ans[i].push_back(cu);
                    ans[i].push_back(cur+1-prv-cu);
                    if(cur != n-1)
                        ans[i].push_back(n-cur-1);
                }
            }
            else
            {
                if(!as)
                {
                    for(j=0;j<=cur;j++)
                        ans[i].push_back(1);
                    ans[i].push_back(prv-cur);
                    for(j=prv+1;j<n;j++)
                        ans[i].push_back(1);
                }
                else
                {
                    for(j=0;j<cur;j++)
                        ans[i].push_back(1);
                    ans[i].push_back(prv-cur);
                    for(j=prv;j<n;j++)
                        ans[i].push_back(1);
                }
            }
            merge(v,ans[i]);
        }
    }
    int sum = 0;
    for(i=0;i<n;i++)
    {
        if(ans[i].size() > 0)
            sum++;
    }
    if(n == 1)
    {
        cout<<0;
        return 0;
    }
    bool inv = false;
    int nxt,prv;
    for(i=0;i<n;i++)
    {
        if(v[i] == 1)
            nxt = i;
        if(v[i] == 0)
            prv= i;
    }
    if(nxt < prv)
        inv = true;
    if(inv)
        sum++;
    cout<<sum<<endl;
    for(i=n-1;i>=0;i--)
    {
        if(ans[i].size() > 0)
        {
            cout<<ans[i].size()<<' ';
            for(auto it: ans[i])
                cout<<it<<' ';
            cout<<endl;
        }
    }
    if(n != 1 && inv)
    {
        cout<<n<<' ';
        for(i=0;i<n;i++)
            cout<<1<<' ';
    }
    return 0;
}