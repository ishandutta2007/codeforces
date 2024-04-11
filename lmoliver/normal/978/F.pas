var id,a,mr,ans:array[0..200000]of longint;n,i,j,k,x,y,l,r,mid:longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[random(r-l+1)+l];
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
                y:=id[i];
                id[i]:=id[j];
                id[j]:=y;
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
randomize;
  read(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do id[i]:=i;
  sort(1,n);
  for i:=1 to n do mr[id[i]]:=i;
  for i:=1 to n do
  begin
    l:=0;r:=n;
    while l<r do
    begin
      mid:=(l+r+1)div 2;
      if a[mid]<a[i]then l:=mid else r:=mid-1;
    end;
    ans[i]:=l;
  end;
  for i:=1 to k do
  begin
    read(x,y);
    x:=mr[x];y:=mr[y];
    if a[x]<>a[y] then
    begin
    if x>y then dec(ans[x])
    else dec(ans[y]);
    end;
  end;
  for i:=1 to n do write(ans[mr[i]],' ');
end.