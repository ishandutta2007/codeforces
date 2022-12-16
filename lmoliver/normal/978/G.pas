var a,b,c,s,d,id,ans:array[1..1000]of longint;i,j,n,m:longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=s[i];
                s[i]:=s[j];
                s[j]:=y;
                y:=c[i];c[i]:=c[j];c[j]:=y;
                y:=id[i];id[i]:=id[j];id[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
  read(n,m);
  for i:=1 to n do ans[i]:=0;
  for i:=1 to m do id[i]:=i;
  for i:=1 to m do read(s[i],a[i],c[i]);
  for i:=1 to m do ans[a[i]]:=m+1;
  sort(1,m);
  for i:=1 to m do
  begin
    for j:=s[i] to a[i]-1 do
    begin
      if ans[j]=0 then
      begin
        ans[j]:=id[i];
        dec(c[i]);
        if c[i]=0 then break;
      end;
    end;
    if c[i]>0 then begin writeln(-1);exit;end;
  end;
  for i:=1 to n do write(ans[i],' ');
end.