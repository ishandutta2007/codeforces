
#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],both[200005],a0[200005];
struct ura
{
    long long x,a,b,pz;
}v[200005];
struct ura1
{
    long long x,a,pz;
}a1[200005],b1[200005],ap[200005],bp[200005],bothp[200005],a0p[200005];
bool cmp (ura a, ura b)
{
    return a.x<b.x;
}
bool cmp1 (ura1 a, ura1 b)
{
    return a.x<b.x;
}
int ocp[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k;
    cin>>n>>m>>k;
    long long n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0;
    for(i=1;i<=n;++i)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        if(y+z==2)
            both[++n3]=x,bothp[n3]={x,0,i};
        else if(y==1)
            a[++n1]=x,ap[n1]={x,0,i};
        else if(z==1)
            b[++n2]=x,bp[n2]={x,0,i};
        if(y+z<=1)
            v[++n4]={x,y,z,i};
        if(y==1 && z==0 || y+z==0)
            a1[++n5]={x,y+z,i};
        if(y==0 && z==1 || y+z==0)
            b1[++n6]={x,y+z,i};
        if(y+z==0)
            a0[++n7]=x,a0p[n7]={x,0,i};
    }
    sort(a+1,a+n1+1);
    sort(ap+1,ap+n1+1,cmp1);
    sort(b+1,b+n2+1);
    sort(bp+1,bp+n2+1,cmp1);
    sort(both+1,both+n3+1);
    sort(bothp+1,bothp+n3+1,cmp1);
    sort(v+1,v+n4+1,cmp);
    sort(a0+1,a0+n7+1);
    sort(a0p+1,a0p+n7+1,cmp1);
    sort(a1+1,a1+n5+1,cmp1);
    sort(b1+1,b1+n6+1,cmp1);
    for(i=1;i<=n4;++i)
    {
        v[i].x+=v[i-1].x;
        v[i].a+=v[i-1].a;
        v[i].b+=v[i-1].b;
    }
    for(i=1;i<=n5;++i)
    {
        a1[i].x+=a1[i-1].x;
        a1[i].a+=a1[i-1].a;
    }
    for(i=1;i<=n6;++i)
    {
        b1[i].x+=b1[i-1].x;
        b1[i].a+=b1[i-1].a;
    }
    for(i=1;i<=n7;++i)
        a0[i]+=a0[i-1];
    for(i=1;i<=n1;++i)
        a[i]+=a[i-1];
    for(i=1;i<=n2;++i)
        b[i]+=b[i-1];
    long long mn=999999999999999LL;
    long long sc=0;
    i=0;
    int whati=-1;
    while(n1>=k && n2>=k)
    {
        i=0;
        sc+=both[i];
        if(i+(k-i)*2>m || n1<k-i || n2<k-i)
            break;
        long long ram=m-i;
        long long ca=v[ram].a;
        long long cb=v[ram].b;
        if(ca>=k-i && cb>=k-i && n4>=ram)
        {
            if(sc+v[ram].x<mn)
            {
                mn=sc+v[ram].x;
                whati=i;
            }
        }
        else if(ca>=k-i && cb<k-i)
        {
            long long sc1=sc+b[k-i];
            ram=m-k;
            ca=a1[ram].a;
            if(ca>=k-i)
            {
                sc1+=a1[ram].x;
                if(n2>=k-i && n5>=ram)
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
            else
            {
                sc1+=a[k-i]+a0[m-(i+k-i+k-i)];
                if(n2>=k-i && n1>=k-i && n7>=m-(i+k-i+k-i))
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
        }
        else if(ca<k-i && cb>=k-i)
        {
            long long sc1=sc+a[k-i];
            ram=m-k;
            cb=b1[ram].a;
            if(cb>=k-i)
            {
                sc1+=b1[ram].x;
                if(n6>=ram)
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
            else
            {
                sc1+=b[k-i]+a0[m-(i+k-i+k-i)];
                if(n2>=k-i && n1>=k-i && n7>=m-(i+k-i+k-i))
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
        }
        else
        {
            long long sc1=sc+a[k-i]+b[k-i]+a0[m-(i+k-i+k-i)];
            if(n2>=k-i && n1>=k-i && n7>=m-(i+k-i+k-i))
                    {if(sc1<mn)mn=sc1,whati=i;}
        }
        break;
    }
    for(i=1;i<=min(n3,m);++i)
    {
        sc+=both[i];
        if(i>=k)
        {
            long long sc1=sc+v[m-i].x;
            if(n4>=m-i)
                {if(sc1<mn)mn=sc1,whati=i;}
            continue;
        }
        if(i+(k-i)*2>m || n1<k-i || n2<k-i)
            continue;
        long long ram=m-i;
        long long ca=v[ram].a;
        long long cb=v[ram].b;
        if(ca>=k-i && cb>=k-i && n4>=ram)
        {
            if(sc+v[ram].x<mn)
            {
                mn=sc+v[ram].x;
                whati=i;
            }
        }
        else if(ca>=k-i && cb<k-i)
        {
            long long sc1=sc+b[k-i];
            ram=m-k;
            ca=a1[ram].a;
            if(ca>=k-i)
            {
                sc1+=a1[ram].x;
                if(n2>=k-i && n5>=ram)
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
            else
            {
                sc1+=a[k-i]+a0[m-(i+k-i+k-i)];
                if(n2>=k-i && n1>=k-i && n7>=m-(i+k-i+k-i))
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
        }
        else if(ca<k-i && cb>=k-i)
        {
            long long sc1=sc+a[k-i];
            ram=m-k;
            cb=b1[ram].a;
            if(cb>=k-i)
            {
                sc1+=b1[ram].x;
                if(n6>=ram)
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
            else
            {
                sc1+=b[k-i]+a0[m-(i+k-i+k-i)];
                if(n2>=k-i && n1>=k-i && n7>=m-(i+k-i+k-i))
                    {if(sc1<mn)mn=sc1,whati=i;}
            }
        }
        else
        {
            long long sc1=sc+a[k-i]+b[k-i]+a0[m-(i+k-i+k-i)];
            if(n2>=k-i && n1>=k-i && n7>=m-(i+k-i+k-i))
                    {if(sc1<mn)mn=sc1,whati=i;}
        }
    }
    if(mn==999999999999999LL)
    {
        cout<<-1<<'\n';
        return 0;
    }
    else
        cout<<mn<<'\n';
    sc=0;
    for(i=1;i<=whati;++i)
        sc+=both[i];
    i=whati;
    while(1){ /// ------------------------------------------------
    for(j=1;j<=i;++j)
        ocp[bothp[j].pz]=1;
    if(i>=k)
    {
        long long sc1=sc+v[m-i].x;
        for(j=1;j<=m-i;++j)
            ocp[v[j].pz]=1;
        break;
    }
    long long ram=m-i;
    long long ca=v[ram].a;
    long long cb=v[ram].b;
    if(ca>=k-i && cb>=k-i && n4>=ram)
    {
        for(j=1;j<=m-i;++j)
            ocp[v[j].pz]=1;
    }
    else if(ca>=k-i && cb<k-i)
    {
        long long sc1=sc+b[k-i];
        ram=m-k;
        ca=a1[ram].a;
        if(ca>=k-i)
        {
            sc1+=a1[ram].x;
            for(j=1;j<=k-i;++j)
                ocp[bp[j].pz]=1;
            for(j=1;j<=ram;++j)
                ocp[a1[j].pz]=1;
        }
        else
        {
            sc1+=a[k-i]+a0[m-(i+k-i+k-i)];
            for(j=1;j<=k-i;++j)
                ocp[bp[j].pz]=1;
            for(j=1;j<=k-i;++j)
                ocp[ap[j].pz]=1;
            for(j=1;j<=m-(i+k-i+k-i);++j)
                ocp[a0p[j].pz]=1;
        }
    }
    else if(ca<k-i && cb>=k-i)
    {
        long long sc1=sc+a[k-i];
        ram=m-k;
        cb=b1[ram].a;
        if(cb>=k-i)
        {
            sc1+=b1[ram].x;
            for(j=1;j<=k-i;++j)
                ocp[ap[j].pz]=1;
            for(j=1;j<=ram;++j)
                ocp[b1[j].pz]=1;
        }
        else
        {
            sc1+=b[k-i]+a0[m-(i+k-i+k-i)];
            for(j=1;j<=k-i;++j)
                ocp[bp[j].pz]=1;
            for(j=1;j<=k-i;++j)
                ocp[ap[j].pz]=1;
            for(j=1;j<=m-(i+k-i+k-i);++j)
                ocp[a0p[j].pz]=1;
        }
    }
    else
    {
        long long sc1=sc+a[k-i]+b[k-i]+a0[m-(i+k-i+k-i)];
        for(j=1;j<=k-i;++j)
            ocp[bp[j].pz]=1;
        for(j=1;j<=k-i;++j)
            ocp[ap[j].pz]=1;
        for(j=1;j<=m-(i+k-i+k-i);++j)
            ocp[a0p[j].pz]=1;
    }
    break;
    }
    for(i=1;i<=n;++i)
        if(ocp[i])
            cout<<i<<' ';
    return 0;
}