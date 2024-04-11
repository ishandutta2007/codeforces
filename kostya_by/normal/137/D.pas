program p1;

uses math;

var
        st,ans : ansistring;
        f, g, from : array[0..500,0..500] of longint;
        i,j,k,n,m,kk : longint;
        res, now, prev : longint;

procedure findg(ll, rr: longint);
var
        res : longint;
begin
        if g[ll,rr] <> -1 then exit;
        if ll = rr then begin
                g[ll,rr]:=0;
                exit;
        end;
        if ll + 1 = rr then begin
                if st[ll] <> st[rr] then g[ll, rr]:=1 else g[ll, rr]:=0;
                exit;
        end;
        findg(ll + 1, rr - 1);
        res:=g[ll + 1, rr - 1];
        if st[ll] <> st[rr] then inc(res);
        g[ll, rr]:=res;
end;

function fun(ll, rr : longint):ansistring;
var
        res1, res2 : ansistring;
        i, l, r : longint;
begin
        res1:=''; res2:='';
        l:=ll; r:=rr;
        while l < r do begin
                res1:=res1 + st[l];
                res2:=st[l] + res2;
                inc(l); dec(r);
        end;
        if l = r then res1:=res1 + st[l];
        exit(res1 + res2);
end;

begin
        readln(st);
        readln(kk);
        for i:=0 to 500 do
                for j:=0 to 500 do begin
                        f[i][j]:=20000;
                        g[i][j]:=-1;
                end;
        f[0][0]:=0;
        n:=length(st);
        for i:=1 to n do
                for j:=i to n do
                        findg(i,j);
        for i:=1 to n do begin
                for j:=1 to kk do begin
                        res:=20000;
                        from[i,j]:=-1;
                        for k:=1 to i do begin
                                prev:=i - k;
                                if f[prev,j - 1] = 20000 then continue;
                                if res > f[prev,j - 1] + g[prev + 1, i] then begin
                                        res:=f[prev,j - 1] + g[prev + 1, i];
                                        from[i,j]:=prev;
                                end;
                        end;
                        f[i,j]:=res;
                end;
        end;
        res:=20000;
        for i:=1 to kk do if f[n,i] < res then begin
                res:=f[n,i];
                k:=i;
        end;
        now:=n;
        ans:='';
        //writeln(1);
        //writeln(from[n,1]);
        while now <> 0 do begin
                //writeln(from[now, k] + 1,' ',now,' ',k);
                ans:=fun(from[now, k] + 1, now) + '+' + ans;
                now:=from[now, k]; dec(k);
        end;
        writeln(res);
        for i:=1 to length(ans) - 1 do write(ans[i]);

end.