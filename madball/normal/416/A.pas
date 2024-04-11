program Gaem;

const GMin = -2000000000;
      GMax = 2000000000;

function max(a,b:longint):longint;
begin
if a > b then max := a
   else max := b;
end;

function min(a,b:longint):longint;
begin
if a < b then min := a
   else min := b;
end;

var N,cur,cmin,cmax : longint;
    s,ns : string[2];
    c1,c : char;

begin
readln(N);
cmin := GMin;
cmax := GMax;


while N > 0 do
      begin
      dec(N);

      readln(s,cur,c1,c);
      if s[2] = ' ' then s := s[1];

      ns := s;
      if c = 'N' then
         begin
         if s = '>=' then ns := '<';
         if s = '>' then ns := '<=';
         if s = '<=' then ns := '>';
         if s = '<' then ns := '>=';
         end;

      if ns = '>' then
         begin
         ns := '>=';
         inc(cur);
         end;

      if ns = '<' then
         begin
         ns := '<=';
         dec(cur);
         end;

      if ns = '>=' then
         cmin := max(cmin,cur);

      if ns = '<=' then
         cmax := min(cmax,cur);
      end;

if cmax < cmin then writeln('Impossible')
   else writeln(cmin);
end.