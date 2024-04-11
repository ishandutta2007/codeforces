var
s:string;
n,r,d,i,j,k,max:longint;
begin
max:=0;
readln(d,n);
for i:=1 to n do
 begin
  readln(s);
  r:=0;
  for j:=1 to length(s) do begin
   if s[j]='0' then begin r:=1;break;end;        end;
  if r=1 then inc(k) else k:=0;

  {writeln(k,r,s[2]);   }
  if k>max then max:=k;
 end;
 write(max);
end.