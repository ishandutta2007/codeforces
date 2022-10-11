const
   fin='d110062016.inp';fon='d110062016.out';
var i,j,r,c,d:longint; s:string;
   a:array[1..1000,1..1001] of string;
procedure solve;
begin
readln(r,c);
for i:=1 to r do
   begin
   readln(s);
   for j:=1 to length(s) do
      a[i,j]:=s[j];
   end;
j:=2; d:=0;
while j<=c do
   begin
   if a[r,j]='.' then
      begin
      if a[r,j-1]='B' then inc(d);
      end;
   inc(j);
   end;
if a[r,c]='B' then inc(d);
write(d);
end;

begin
//assign(input,fin);reset(input);
//assign(output,fon);rewrite(output);
solve;
end.