#pragma GCC optimize ("O2")
#pragma G++ optimize ("O2")
#include <bits/stdc++.h>
using namespace std;

#define QUICK

#ifdef QUICK
    #define R register
#else
    #define R 
#endif

//deque
ostream& operator << (ostream &out,deque<int>& x)
{
    for (R deque<int>::iterator it=x.begin();it!=x.end();it++)
    {
        out<<char(*it+'0');
    }
    out<<std::endl;
    return out;
};

int main()
{
#ifdef QUICK
    ios::sync_with_stdio(false);//
#endif
    deque<int> a,b,s,c,d,n;
    //a,b
    //c,d
    //s,n
    int l;
    cin>>l;
    for (R int point=1;point<=l;point++)
    {
        char t;
        cin>>t;
        if(point<=l/2)
        {
            a.push_back(t-'0');
            c.push_back(t-'0');
        }//
        else
        {
            b.push_back(t-'0');
            d.push_back(t-'0');
        }//
    }
    a.push_back(b.front());
    b.pop_front();
    a.push_back(b.front());
    b.pop_front();
    d.push_front(c.back());
    c.pop_back();
        //
    while(!a.empty())
    {
        b.push_front(a.back());
        a.pop_back();
        if(a.empty()||b.empty()||a.front()==0||b.front()==0)
        {//0
            continue;
        }
        deque<int>::reverse_iterator pa=a.rbegin(),pb=b.rbegin();
            //
        int g=0;
            //
        for(;pa!=a.rend()&&pb!=b.rend();++pa,++pb)
        {
            s.push_front((*pa+*pb+g)%10);
            g=(*pa+*pb+g)/10;
        }
        while(pa!=a.rend())
        {
            s.push_front((*pa+g)%10);
            g=(*pa+g)/10;
            pa++;
        }
        while(pb!=b.rend())
        {
            s.push_front((*pb+g)%10);
            g=(*pb+g)/10;
            pb++;
        }
        if(g!=0)
        {
            s.push_front(g);
        }
        break;
    }   
        //
    while(!d.empty())
    {
        c.push_back(d.front());
        d.pop_front();
        if(c.empty()||d.empty()||c.front()==0||d.front()==0)
        {
            continue;
        }
        deque<int>::reverse_iterator pc=c.rbegin(),pd=d.rbegin();
        int g=0;
        for(;pc!=c.rend()&&pd!=d.rend();++pc,++pd)
        {
            n.push_front((*pc+*pd+g)%10);
            g=(*pc+*pd+g)/10;
        }
        while(pc!=c.rend())
        {
            n.push_front((*pc+g)%10);
            g=(*pc+g)/10;
            pc++;
        }
        while(pd!=d.rend())
        {
            n.push_front((*pd+g)%10);
            g=(*pd+g)/10;
            pd++;
        } 
        if(g!=0)
        {
            n.push_front(g);
        }
        break;
    }
//  cout<<a<<b<<c<<d<<s<<n;
    //sn
    if(s.size()==0) 
    {
        cout<<n<<std::endl;
        return 0;
    }
    if(n.size()==0)
    {
        cout<<s<<std::endl;
        return 0;
    }
    if(s.size()!=n.size())
    {
        if(s.size()<n.size())
        {
            cout<<s<<std::endl;
        } 
        else
        {
            cout<<n<<std::endl;
        }
        return 0;
    }
    else
    {//
        deque<int>::iterator ps=s.begin(),pn=n.begin();
        for(;ps!=s.end()&&pn!=n.end();ps++,pn++)
        {
            if(*pn!=*ps)
            {
                if(*ps<*pn)
                {
                    cout<<s<<std::endl;
                } 
                else
                {
                    cout<<n<<std::endl;
                }
                return 0;
            } 
        }
    }
    cout<<n<<std::endl;
    return 0;
}