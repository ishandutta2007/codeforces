program sdfksdpfsdof;

{$APPTYPE CONSOLE}

var
   a,b : array [1..1001] of string[4];
   n,i : longint;

procedure convent(num : longint; sta: string);
var
   max,st : string;
   i,j,k,l,i1,s : longint;
   ch,ch1: char;
begin
     max:=b[num + 1];
     for i:=2 downto 1 do begin
      for j:=9 downto 0 do begin
        for k:=9 downto 0 do begin
          for l:=9 downto 0 do begin
            st:=chr(48+i) + char(48+j) + char(48+k) + chr(48+l);
            if st <= max then begin
              s:=0;
              for i1:=1 to 4 do begin
                if st[i1] = sta[i1] then inc(s);
              end;
              if (s = 3) or (s = 4) then begin
                b[num]:=st;
                exit;
              end;
            end;
          end;
        end;
      end;
     end;
     writeln('No solution');
     readln(n);
     halt;
end;

begin
     readln(n);
     for i:=1 to n do readln(a[i]);
     b[n+1]:='2011';
     for i:=n downto 1 do begin
         convent(i,a[i]);
     end;
     for i:=1 to n do writeln(b[i]);
     readln(n);
end.