/**TBH, I never expected Ithea to be one of the best girl in sukasuka.**/
#include<bits/stdc++.h>
using namespace std;
int T;
string s;

int check(int deep, int depth[],int des, int n)
{
    int i,counti = 0;
    for(i=0;i<n;i++)
        if(depth[i] == deep)
            counti++;
    if(counti == 0)
        return -1;
    else
    {
        cout<<"? "<<counti<<" ";
        for(i=0;i<n;i++)
            if(depth[i]==deep)
                cout<<i+1<<" ";
        cout<<"\n";
        int a,b;
        cin>>a>>b;
        if(b!=des)
            return -1;
        else
            return a-1;
    }
}

int spec_check(int deep, int depth[],int des, int n, int can)
{
    int i,counti = 0;
    for(i=0;i<n;i++)
        if(depth[i] == deep && i!=can)
            counti++;
    if(counti == 0)
        return -1;
    else
    {
        cout<<"? "<<counti<<" ";
        for(i=0;i<n;i++)
            if(depth[i]==deep && i!=can)
                cout<<i+1<<" ";
        cout<<"\n";
        int a,b;
        cin>>a>>b;
        if(b!=des)
            return -1;
        else
            return a-1;
    }
}

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,j;
        cin>>n;
        vector<int> tree[n];
        int depth[n];
        int prv[n];
        depth[n-1] = -1;
        for(i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            tree[a-1].push_back(b-1);
            tree[b-1].push_back(a-1);
            depth[i] = -1;
        }
        cout<<"? "<<n<<" ";
        for(i=0;i<n;i++)
            cout<<i+1<<" ";
        cout<<"\n";
        fflush(stdout);
        int root, path_length;
        cin>>root>>path_length;
        root--;
        stack<int> st;
        st.push(root);
        depth[root] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it: tree[node])
                if(depth[it] == -1)
                {
                    st.push(it);
                    depth[it] = depth[node] + 1;
                    prv[it] = node;
                }
        }
        int l = (path_length+1)/2, r = path_length;
        int can=-99,impe=-99;
        while(l<r)
        {
            int mid = l+r >> 1;
            if(mid == l)
            {
                can = check(r,depth,path_length,n);
                if(can!=-1)
                {
                    l = r;
                    impe = can;
                }
                else
                    r = l;
            }
            else
            {
                can = check(mid,depth,path_length,n);
                if(can!=-1)
                {
                    l = mid;
                    impe = can;
                }
                else
                    r = mid-1;
            }
        }
        if(impe == -99)
            impe = check(l,depth,path_length,n);
        int cur = impe;
        while(cur!=root)
        {
            depth[cur] = -1;
            cur = prv[cur];
        }
        int ss = spec_check(path_length-l,depth,path_length,n,impe);
        cout<<"! "<<ss+1<<" "<<impe+1<<"\n";
        fflush(stdout);
        cin>>s;
        if(s!="Correct")
            break;
    }
    return 0;
}