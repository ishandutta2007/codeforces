var n,a:integer;
begin
    read(n);
    if n <= 9 then write(n)
    else
        begin
            if n <= 189 then
                begin
                    a := (n - 10) div 2 + 10;
                    if (n mod 2 = 0) then write(a div 10) else write(a mod 10);
                end
            else
                begin
                    a := (n - 190) div 3 + 100;
                    if (n mod 3 = 1) then write(a div 100);
                    if (n mod 3 = 2) then write(a div 10 - 10*(a div 100));
                    if (n mod 3 = 0) then write(a mod 10);
                end;
        end;
end.