var n,m,l,r,mid,i:longint;a,s:array[0..200000]of int64;b:int64;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do s[i]:=s[i-1]+a[i];
  for i:=1 to m do
  begin
    read(b);
    l:=1;
    r:=n;
    while l<r do
    begin
      mid:=(l+r)div 2;
      if s[mid]>=b then r:=mid else l:=mid+1;
    end;
    writeln(l,' ',b-s[l-1]);
  end;
end.