        #include <bits/stdc++.h>
         
        using namespace std;
        long long v[500005];
        long long v1[403][403];
        int main()
        {
            ios_base::sync_with_stdio(0);
            long long t,n,i,j,cnt=0,m,p,h,a,b,sc=1,q,s,x,y;
            cin>>q;
            while(q--)
            {
                x,y;
                cin>>t>>x>>y;
                if(t==1)
                {
                    v[x]+=y;
                    for(i=1;i<=400;++i)
                        v1[i][x%i]+=y;
                }
                else
                {
                    s=0;
                    if(x>400)
                        for(i=y;i<=500000;i+=x)
                            s+=v[i];
                    else
                        s+=v1[x][y];
                    cout<<s<<'\n';
                }
            }
            return 0;
        }