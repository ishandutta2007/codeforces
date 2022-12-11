program Project1;

var
   f : array[0..1000,0..1000] of longint;
   c,d : array[1..1000] of longint;
   i,j,k,n,m,c0,d0,an,bn,cn,dn,ans,now,h : longint;
begin
     read(n,m,c0,d0);
     h:=0;
     for i:=1 to m do begin
         read(an,bn,cn,dn);
         for j:=1 to (an div bn) do begin
             inc(h);
             c[h]:=cn;
             d[h]:=dn;
         end;
     end;
     for i:=0 to 1000 do
         for j:=0 to 1000 do
             f[i,j]:=-1;
     for i:=0 to 1000 do f[0,i]:=0;
     m:=h;
     for i:=1 to n do begin
         for j:=1 to m do begin
             f[i,j]:=f[i,j - 1];
             k:=i - c[j];
             if k < 0 then continue;
             if f[k,j - 1] = -1 then continue;
             if f[i,j] < f[k,j - 1] + d[j] then f[i,j]:=f[k,j - 1] + d[j];
         end;
     end;
     ans:=0;
     for i:=0 to n do begin
         now:=f[i,m] + (((n - i) div c0) * d0);
         if now > ans then ans:=now;
     end;
     writeln(ans);
end.