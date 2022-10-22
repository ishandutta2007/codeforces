uses math;
var n,s,k,x,i,ans,t,j:longint;b:array[0..5000]of longint;
function hash(k:longint):longint;
var t:longint;
begin
  t:=k mod 5000;
  while b[t]<>0 do
  begin
    inc(t);
    t:=t mod 5000;
  end;
  b[t]:=k;
  exit(t);
end;
function hash1(k:longint):longint;
var t:longint;
begin
  t:=k mod 5000;
  while (b[t]<>k)and(b[t]<>0) do
  begin
    inc(t);
    t:=t mod 5000;
  end;
  exit(t);
end;
begin
  read(t);
  for j:=1 to t do
  begin
    read(n,s,k);
    fillchar(b,sizeof(b),0);
    ans:=maxlongint;
    for i:=1 to k do
    begin
      read(x);
      hash(x);
    end;
    for i:=s to n do
      if b[hash1(i)]<>i then
      begin
        ans:=min(ans,i-s);
        break;
      end;
    for i:=s downto 1 do
      if b[hash1(i)]<>i then
      begin
        ans:=min(ans,s-i);
        break;
      end; 
    writeln(ans);
  end;
end.