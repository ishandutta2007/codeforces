uses math;
var n,m,k,t,i1,i,ans,l,r,ans1,j:longint;a:array[0..10000]of longint;
begin
  readln(t);
  for i1:=1 to t do
  begin
    readln(n,m,k);
    for i:=1 to n do read(a[i]);
    k:=min(k,m-1);
    ans:=0;
    for i:=1 to n+1 do
    begin
      if i-1>k then break;
      l:=i;r:=n-(k-i+1);
      ans1:=maxlongint;
      for j:=l to r+1 do
      begin
        if j-l>(m-k-1) then break;
        ans1:=min(ans1,max(a[j],a[r-((m-k-1)-(j-l))]));
      end;
      ans:=max(ans,ans1);
    end;
    writeln(ans);
  end;
end.