class solver_1684E:

    def __init__(self):
        self.n,self.k=list(map(int,input().split(' ')));
        self.inp=list(map(int,input().split(' ')));

    def eval(self,mex):

        seen = {};

        for val in self.inp:
            if val in seen:
                seen[val] = seen[val] + 1;
            else:
                seen[val] = 1;

        low=mex;
        high=0;

        for i in range(0,mex):
            if i in seen:
                low=low-1;

        for val in self.inp:
            if val>=mex:
                high=high+1;

        #print("low=",low,"high=",high,self.k);

        if low>self.k or high<low:
            return -1;

        sub = [];

        for val in self.inp:
            if val > mex and seen[val]:
                sub.append(seen[val]);
                seen[val] = 0;

        sub.sort();

        diff = mex;

        #print("mex=", mex, "diff=", diff, "sub=", sub);

        mem_k=self.k;

        for i in sub:

            rem=min(mem_k,i);

            mem_k=mem_k-rem;

            if i>rem:
                diff=diff+1;

        #print("mex=",mex,"diff=",diff);

        return diff - mex;

    def solve(self):

        ok=-1;
        not_ok=self.n+1;

        outp=self.n;

        while not_ok-ok>1:
            av=(ok+not_ok)//2;

            cur=self.eval(av);

            #print("av=",av,"cur=",cur);

            if cur==-1:
                not_ok=av;
            else:
                ok=av;
                outp=cur;

        return outp;

t=int(input());

while t:
    t=t-1;

    cur=solver_1684E();

    print(cur.solve());